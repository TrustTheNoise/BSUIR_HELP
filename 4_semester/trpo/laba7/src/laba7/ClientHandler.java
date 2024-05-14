package laba7;
import java.io.*;
import java.net.*;
import java.util.*;

class ClientHandler implements Runnable {
    private Socket socket;
    private BufferedReader in;
    private PrintWriter out;
    private String name;

    public ClientHandler(Socket socket) {
        this.socket = socket;
    }
    
    public Socket getSocket() {
        return socket;
    }
    
    @Override
    public void run() {
        try {
        	// Создаем объект BufferedReader для чтения входящих данных из сокета
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		    
            // Создаем объект PrintWriter для записи выходящих данных в сокет
            // буфер будет автоматически сбрасываться при записи данных
            out = new PrintWriter(socket.getOutputStream(), true);

            out.println("Enter your name:");
            name = in.readLine();

            Server.addClientName(name, this);
            Server.broadcastMessage(name + " has joined the chat.");

            String message;
            while ((message = in.readLine()) != null) {
                Server.broadcastMessage(name + ": " + message);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                in.close();
                out.close();
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            Server.removeClientName(name);
            Server.broadcastMessage(name + " has left the chat.");
        }
    }

    public void sendMessage(String message) {
        out.println(message);
    }
}

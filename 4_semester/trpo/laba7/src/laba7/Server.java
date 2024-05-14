package laba7;

import java.io.*;
import java.net.*;
import java.util.*;

public class Server {
    private static final int PORT = 1234;
    private static Map<String, ClientHandler> clientNames = new HashMap<>();
    private static final String CLIENT_FILE = "clients.txt";

    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(PORT);
        System.out.println("Server started on port " + PORT);

        while (true) {
        	// блокируем выполнение кода пока не будет установленно входящее
        	// подключение на порту
            Socket socket = serverSocket.accept();
            
            // создаём клиента с новым сокетом
            ClientHandler clientHandler = new ClientHandler(socket);
            
            // начинаем поток для обработки сообщений нашего нового пользователя
            new Thread(clientHandler).start();
        }
    }

    public static void broadcastMessage(String message) {
    	// отправяляем всем клиентам сообщения
        for (ClientHandler client : clientNames.values()) {
            client.sendMessage(message);
        }
    }

    public static void addClientName(String name, ClientHandler client) {
        clientNames.put(name, client);
        saveClientsToFile();
    }

    public static void removeClientName(String name) {
        clientNames.remove(name);
        saveClientsToFile();
    }

    private static void saveClientsToFile() {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(CLIENT_FILE))) {
            for (Map.Entry<String, ClientHandler> entry : clientNames.entrySet()) {
                String name = entry.getKey();
                Socket socket = entry.getValue().getSocket();
                String address = socket.getInetAddress().getHostAddress() + ":" + socket.getPort();
                bw.write(name + ":" + address);
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
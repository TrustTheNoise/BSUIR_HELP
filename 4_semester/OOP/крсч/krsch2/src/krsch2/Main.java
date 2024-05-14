package krsch2;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Device[] devices1 = {
                new CPU("Intel Core i5", 200, 4, 3.1),
                new RAM("Corsair Vengeance LPX 16GB", 80, 16),
                new VideoCard("Gigabyte GeForce GTX 1650", 150, 6.13),
                new Motherboard("ASUS ROG Strix B450-F Gaming", 150.0, "AMD B450")
        };

        Device[] devices2 = {
                new CPU("AMD Ryzen 7 3700X", 300, 8, 3.6),
                new RAM("G.Skill Ripjaws V 32GB", 160, 32),
                new VideoCard("ASUS ROG Strix Radeon RX 5700 XT", 400, 20.58),
                new Motherboard("Gigabyte Aorus X570 Pro Wi-Fi", 250.0, "AMD X570")
        };
        
        Device[] devices3 = {
                new CPU("Intel Xeon E5-2690 v4", 1000, 14, 2.6),
                new RAM("Kingston ValueRAM 64GB", 320, 64),
                new VideoCard("NVIDIA Quadro RTX 6000", 4000, 130),
                new Motherboard("ASUS TUF B460M-PRO", 150.0, "Intel B460")
        };
        
        Computer workComputer = new Computer("Work computer", devices1);
        Computer gamingComputer = new Computer("Gaming computer", devices2);
        Computer server = new Computer("Server", devices3);
        
        System.out.println(workComputer + "\n");
        System.out.println(gamingComputer + "\n");
        System.out.println(server + "\n");
        
	}
}

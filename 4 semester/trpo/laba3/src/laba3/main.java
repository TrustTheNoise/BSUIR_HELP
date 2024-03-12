package laba3;

import java.io.*;
import java.nio.file.*;
import java.util.stream.Stream;

import static java.nio.file.StandardOpenOption.*;

public class main {

    // Функция шифрования Цезаря (Rot8)
    public static char encryptChar(char c) {
        if (Character.isAlphabetic(c)) {
            char base = Character.isLowerCase(c) ? 'a' : 'A';
            return (char) ((c - base + 8) % 26 + base);
        }
        return c;
    }

    // Функция для определения суммы всех целых чисел в строке
    public static int sumOfIntegers(String str) {
        int sum = 0;
        StringBuilder numStr = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            if (Character.isDigit(str.charAt(i))) {
                numStr.append(str.charAt(i));
            } else if (!numStr.toString().isEmpty()) {
                sum += Integer.parseInt(numStr.toString());
                numStr.setLength(0);
            }
        }
        if (!numStr.toString().isEmpty()) {
            sum += Integer.parseInt(numStr.toString());
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        Path inputPath = Paths.get("input.txt");
        Path outputPath = Paths.get("output.txt");
        int sum = 0;

        try (BufferedReader inFile = Files.newBufferedReader(inputPath);
             BufferedWriter outFile = Files.newBufferedWriter(outputPath, CREATE, TRUNCATE_EXISTING)) {

            String line;
            while ((line = inFile.readLine()) != null) {
                StringBuilder encryptedLine = new StringBuilder();
                for (int i = 0; i < line.length(); i++) {
                    encryptedLine.append(encryptChar(line.charAt(i)));
                }
                encryptedLine.append('\n');
                sum += sumOfIntegers(line);
                outFile.write(encryptedLine.toString());
            }
        }
        System.out.println("Sum of all integers in the text: " + sum);
    }
}
package laba7;

import java.sql.*;

public class DatabaseConnector {
	// URL для подключения к базе данных MySQL, расположенной на локальном хосте (localhost) на порту 3306 и с именем "sys"
    private static final String URL = "jdbc:mysql://localhost:3306/sys";
    // Имя пользователя для подключения к базе данных
    private static final String USERNAME = "root";
    // Пароль для подключения к базе данных
    private static final String PASSWORD = "lyosharak";
    
    // Объект класса Connection для подключения к базе данных
    private static Connection connection;

    public static Connection getConnection() {
        if (connection == null) {
            try {
                // Загрузка драйвера MySQL Connector/J
                Class.forName("com.mysql.cj.jdbc.Driver");

                // Получение соединения с базой данных
                connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
            } catch (ClassNotFoundException e) {
                System.err.println("Driver not found: " + e.getMessage());
            } catch (SQLException e) {
                System.err.println("Connection error: " + e.getMessage());
            }
        }
        return connection;
    }
}
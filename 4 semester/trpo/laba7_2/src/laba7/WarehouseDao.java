package laba7;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class WarehouseDao {
    // Объявляем объект Connection как поле класса
    private Connection connection;

    // Создаем конструктор, который устанавливает соединение с базой данных
    public WarehouseDao() {
        connection = DatabaseConnector.getConnection();
    }

    // Добавляем метод для закрытия соединения с базой данных
    public void closeConnection() {
        try {
            if (connection != null && !connection.isClosed()) {
                connection.close();
            }
        } catch (SQLException e) {
            System.err.println("Error closing the database connection: " + e.getMessage());
        }
    }

    // Изменяем метод getAllWarehouses() так, чтобы он использовал объект Connection, установленный в конструкторе
    public List<Product> getAllWarehouses() {
        List<Product> products = new ArrayList<>();

        try (PreparedStatement statement = connection.prepareStatement("SELECT * FROM warehouse")) {
            ResultSet resultSet = statement.executeQuery();

            while (resultSet.next()) {
            	int id = resultSet.getInt("id");
                int sector = resultSet.getInt("sector");
                int row = resultSet.getInt("row_elem");
                int quantity = resultSet.getInt("quantity");
                int place = resultSet.getInt("place");
                String date = resultSet.getString("date");

                Product Product = new Product(id, sector, row, place, quantity, date);
                products.add(Product);
            }
        } catch (SQLException e) {
        	System.out.println("Нет такого элемента в базе данных!");
        }

        return products;
    }

    // Добавляем метод для получения склада по id
    public Product getWarehouse(int sector, int row, int place) {
        Product Product = null;

        try (PreparedStatement statement = connection.prepareStatement("SELECT * FROM warehouse WHERE sector = ? AND row_elem = ? AND place = ?")) {
            statement.setInt(1, sector);
            statement.setInt(2, row);
            statement.setInt(3, place);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
            	int id = resultSet.getInt("id");
                int quantity = resultSet.getInt("quantity");
                String date = resultSet.getString("date");

                Product = new Product(id, sector, row, place, quantity, date);
            }
        } catch (SQLException e) {
        	System.out.println("Нет такого элемента в базе данных!");
        	return null;
        }

        return Product;
    }

    // Добавляем метод для добавления нового склада
    public void addWarehouse(Product Product) {
        try (PreparedStatement statement = connection.prepareStatement("INSERT INTO warehouse (id, sector, row_elem, place, quantity, date) VALUES (?, ?, ?, ?, ?, ?)")) {
        	statement.setInt(1, Product.getId());
        	statement.setInt(2, Product.getSector());
        	statement.setInt(3, Product.getRow());
        	statement.setInt(4, Product.getPlace());
            statement.setInt(5, Product.getQuantity());
            statement.setString(6, Product.getDate());

            statement.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Error adding Product: " + e.getMessage());
        }
    }
    
    public List<Product> getWarehousesInDate(String date1, String date2){
    	List<Product> products = new ArrayList<>();

        try (PreparedStatement statement = connection.prepareStatement("SELECT * FROM warehouse WHERE date BETWEEN ? AND ?")) {
        	statement.setString(1, date1);
        	statement.setString(2, date2);
        	ResultSet resultSet = statement.executeQuery();

            while (resultSet.next()) {
            	int id = resultSet.getInt("id");
                int sector = resultSet.getInt("sector");
                int row = resultSet.getInt("row_elem");
                int quantity = resultSet.getInt("quantity");
                int place = resultSet.getInt("place");
                String date = resultSet.getString("date");

                Product Product = new Product(id, sector, row, place, quantity, date);
                products.add(Product);
            }
        } catch (SQLException e) {
        	System.out.println("Нет элементов в периоде с " + date1 + " по " + date2 + " в базе данных!");
        }

        return products;
    }
    
    // Добавляем метод для обновления информации о складе
    public void updateWarehouse(Product product) {
        try (PreparedStatement statement = connection.prepareStatement("UPDATE warehouse SET id = ?, quantity = ?, date = ? WHERE sector = ? AND row_elem = ? AND place = ?")) {
        	statement.setInt(4, product.getSector());
        	statement.setInt(5, product.getRow());
            statement.setInt(6, product.getPlace());
            
            
            statement.setInt(1, product.getId());
            statement.setInt(2, product.getQuantity());
            statement.setString(3, product.getDate());

            statement.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Error updating Product: " + e.getMessage());
        }
    }

    // Добавляем метод для удаления склада по id
    public void deleteWarehouse(int section, int row, int place) {
        try (PreparedStatement statement = connection.prepareStatement("DELETE FROM warehouse WHERE sector = ? AND row_elem = ? AND place = ?")) {
            statement.setInt(1, section);
            statement.setInt(2, row);
            statement.setInt(3, place);
            statement.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Error deleting Product: " + e.getMessage());
        }
    }
}

package laba4;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Warehouse {
    private List<Product> products;

    public Warehouse() {
        products = new ArrayList<>();
    }

    public void addProduct(Product product) {
        products.add(product);
    }

    public void removeProduct(Product product) {
        products.remove(product);
    }

    public Product findProduct(String sector, int row, int place) {
        for (Product product : products) {
            if (product.getSector().equals(sector) && product.getRow() == row && product.getPlace() == place) {
                return product;
            }
        }
        return null;
    }

    public List<Product> getProductsByDate(LocalDate from, LocalDate to) {
        List<Product> productList = new ArrayList<>();
        for (Product product : products) {
            if (product.getDate().isAfter(from) && product.getDate().isBefore(to)) {
                productList.add(product);
            }
        }
        return productList;
    }
}
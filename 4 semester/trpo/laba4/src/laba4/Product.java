package laba4;

import java.time.LocalDate;
import java.util.Objects;

public class Product implements Storable {
    private String sector;
    private int row;
    private int place;
    private LocalDate date;
    private int quantity;

    public Product(String sector, int row, int place, LocalDate date, int quantity) {
        this.sector = sector;
        this.row = row;
        this.place = place;
        this.date = date;
        this.quantity = quantity;
    }

    @Override
    public String getSector() {
        return sector;
    }

    @Override
    public int getRow() {
        return row;
    }

    @Override
    public int getPlace() {
        return place;
    }

    @Override
    public LocalDate getDate() {
        return date;
    }

    @Override
    public int getQuantity() {
        return quantity;
    }

    // переопределение методов equals(), hashCode() и toString()
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Product)) return false;
        Product product = (Product) o;
        return getRow() == product.getRow() &&
                getPlace() == product.getPlace() &&
                getQuantity() == product.getQuantity() &&
                Objects.equals(getSector(), product.getSector()) &&
                Objects.equals(getDate(), product.getDate());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getSector(), getRow(), getPlace(), getDate(), getQuantity());
    }

    @Override
    public String toString() {
        return "Product{" +
                "sector='" + sector + '\'' +
                ", row=" + row +
                ", place=" + place +
                ", date=" + date +
                ", quantity=" + quantity +
                '}';
    }
}

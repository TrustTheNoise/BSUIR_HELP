package laba7;

import java.util.Objects;

public class Product implements Storable {
    private int id;
    private int sector;
    private int row;
    private int place;
    private int quantity;
    private String date;

    public Product(int id, int sector, int row, int place, int quantity, String date) {
        this.id = id;
        this.sector = sector;
        this.row = row;
        this.place = place;
        this.quantity = quantity;
        this.date = date;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
    
    public int getSector() {
        return sector;
    }

    public void setSector(int sector) {
        this.sector = sector;
    }

    public int getRow() {
        return row;
    }

    public void setRow(int row) {
        this.row = row;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public int getPlace() {
        return place;
    }

    public void setPlace(int place) {
        this.place = place;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }
    
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
        		"id= " + id +
                ", sector='" + sector + '\'' +
                ", row=" + row +
                ", place=" + place +
                ", date=" + date +
                ", quantity=" + quantity +
                '}';
    }
}
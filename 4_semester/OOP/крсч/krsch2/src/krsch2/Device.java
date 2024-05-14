package krsch2;

public abstract class Device {
    private String name;
    private double price;

    public Device(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }
}
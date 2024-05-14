package krsch2;

public class RAM extends Device {
    private int capacityGB;

    public RAM(String name, double price, int capacityGB) {
        super(name, price);
        this.capacityGB = capacityGB;
    }

    public int getCapacityGB() {
        return capacityGB;
    }
    
    @Override
    public String toString() {
        return "RAM: " + this.getName() + "  Price: $" + 
        		this.getPrice() + " Capacity: " + 
        		this.capacityGB + " GB" ;
    }
}
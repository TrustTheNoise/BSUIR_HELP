package krsch2;

public class Motherboard extends Device {
    private String chipset;


    public Motherboard(String name, double price, String chipset) {
    	// super обращается к родительскому классу Device и соответственно
    	// вызывает его конструктор с name и price
        super(name, price);
        this.chipset = chipset;
	}

	public String getChipset() {
        return chipset;
    }
    
    @Override
    public String toString() {
        return "Motherboard: " + this.getName() + "  Price: $" + 
        		this.getPrice() + " Chipset: " + 
        		this.chipset;
    }
}
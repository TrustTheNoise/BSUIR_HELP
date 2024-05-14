package krsch2;

public class CPU extends Device {
    private int cores;
    private double frequency;

    public CPU(String name, double price, int cores, double frequency) {
        super(name, price);
        this.cores = cores;
        this.frequency = frequency;
    }

    public int getCores() {
        return cores;
    }

    public double getFrequency() {
        return frequency;
    }
    
    @Override
    public String toString() {
        return "CPU: " + this.getName() + "  Price: $" + 
        		this.getPrice() + " Cores: " + 
        		this.cores + " Frequency: " + this.frequency ;
    }
}

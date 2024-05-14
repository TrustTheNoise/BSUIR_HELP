package krsch2;

public class Computer {
    protected String name;
    protected Device[] devices;

    public Computer(String name, Device[] devices) {
        this.name = name;
        this.devices = devices;
    }

    public double getCost() {
        double cost = 0;
        for (Device device : devices) {
            cost += device.getPrice();
        }
        return cost;
    }
    
    @Override
    public String toString() {
    	 String str = new String();
         str = "Computer: " + this.name;
         
         for (Device device : devices) {
             str += "\n" + device.toString();
         }
         
         str += "\nTotal price: $" + getCost();
         return str;
    }
}
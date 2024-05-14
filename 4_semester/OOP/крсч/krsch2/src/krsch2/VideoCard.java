package krsch2;

public class VideoCard extends Device {
    private double teraflops;

    public VideoCard(String name, double price, double teraflops) {
        super(name, price);
        this.teraflops = teraflops;
    }

    public double getTeraflops() {
        return teraflops;
    }

    public void setTeraflops(int teraflops) {
        this.teraflops = teraflops;
    }
    
    @Override
    public String toString() {
        return "Videocard: " + this.getName() + "  Price: $" + 
        		this.getPrice() + " Teraflops: " + 
        		this.teraflops;
    }
}

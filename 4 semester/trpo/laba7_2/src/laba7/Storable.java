package laba7;


public interface Storable {
    int getSector();
    void setSector(int sector);
    int getRow();
    void setRow(int row);
    int getPlace();
    void setPlace(int place);
    String getDate();
    void setDate(String date);
    int getQuantity();
    void setQuantity(int quantity);
}

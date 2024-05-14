package laba4;

import java.time.LocalDate;

public interface Storable {
    String getSector();
    int getRow();
    int getPlace();
    LocalDate getDate();
    int getQuantity();
}
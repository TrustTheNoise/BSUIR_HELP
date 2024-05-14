package krsch1;

import java.util.Scanner;

public class CBookCard {
    private String author;
    private String title;
    private String publisher;
    private int year;
    private int pages;
    private String udc;
    private int rating;

    public CBookCard(String author, String title, String publisher, int year, int pages, String udc) {
        this.author = author;
        this.title = title;
        this.publisher = publisher;
        this.year = year;
        this.pages = pages;
        this.udc = udc;
        this.rating = 0;
    }
    
    public String getAuthor() {
        return author;
    }

    public String getTitle() {
        return title;
    }

    public String getPublisher() {
        return publisher;
    }

    public int getYear() {
        return year;
    }

    public int getPages() {
        return pages;
    }
    
    public String getUdc() {
        return udc;
    }

    public int getRating() {
        return rating;
    }

    public void setRating(int rating) {
        if (rating >= 0 && rating <= 3) {
            this.rating = rating;
        } else {
            throw new IllegalArgumentException("Рейтинг должен быть в пределах от 0 до 3");
        }
    }

    @Override
    public String toString() {
        return "Автор: " + author +
                "\nЗаглавие: " + title +
                "\nИздательство: " + publisher +
                "\nГод издания: " + year +
                "\nЧисло страниц: " + pages +
                "\nУДК: " + udc.replace(".", " ") +
                "\nРейтинг:    " + rating;
    }
}

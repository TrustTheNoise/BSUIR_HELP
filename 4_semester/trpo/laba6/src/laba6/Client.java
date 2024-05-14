package laba6;

class Client {
    private int id;
    private InsuranceService service;

    public Client(int id, InsuranceService service) {
        this.id = id;
        this.service = service;
    }

    public int getId() {
        return id;
    }

    public InsuranceService getService() {
        return service;
    }
}
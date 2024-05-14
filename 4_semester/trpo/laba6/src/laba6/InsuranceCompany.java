package laba6;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingDeque;

enum InsuranceService {
    AUTO,
    HEALTH,
    LIFE,
    HOME,
    TRAVEL
}

public class InsuranceCompany {
    public static void main(String[] args) {
    	// представляет собой потокобезопасную очередь, основанную на связанном списке. 
    	// добавлять и извлекать элементы в многопоточной среде без необходимости явной синхронизации.
        BlockingQueue<Client> clientQueue = new LinkedBlockingDeque<>();
        
        ExecutorService executorService = Executors.newFixedThreadPool(4);

        executorService.execute(new Manager(1, InsuranceService.AUTO, InsuranceService.HEALTH, clientQueue));
        executorService.execute(new Manager(2, InsuranceService.LIFE, InsuranceService.HOME, clientQueue));
        executorService.execute(new Manager(3, InsuranceService.TRAVEL, InsuranceService.AUTO, clientQueue));
        
        executorService.execute(new ClientGenerator(clientQueue));

        executorService.shutdown();
    }
}
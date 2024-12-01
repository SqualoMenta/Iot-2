import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import javax.swing.SwingUtilities;

public class WasteContainerController {

    SerialCommChannel channel;
    WasteContainerGUI view;
    ExecutorService executor;

    public WasteContainerController(String port, WasteContainerGUI view) throws Exception {
        this.view = view;
        this.executor = Executors.newSingleThreadExecutor();
        this.channel = new SerialCommChannel(port, 9600);
        new MonitoringAgent(channel, this).start();

    }

    public void setUpTemp(String temp) {
        SwingUtilities.invokeLater(() -> view.setUpTemp(temp));
    }

    public void setUpFullness(String fullness) {
        SwingUtilities.invokeLater(() -> view.setUpFullness(fullness));
    }

    public void problemTemp() {
        SwingUtilities.invokeLater(() -> view.problemTemp());
    }

    public void sendClean() {
        executor.submit(()->channel.sendMsg("CLEAN"));
    }

    public void sendRestore() {
        executor.submit(()->channel.sendMsg("RESTORE"));
    }

    public void shutdown(){
        channel.close();
        executor.shutdown();
    }

}

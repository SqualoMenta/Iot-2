import javax.swing.SwingUtilities;

public class SimpleSerialMonitor {

    public static void main(String[] args) throws Exception {
        WasteContainerGUI view;
        if (args.length != 1) {
            System.out.println("args: <CommPortName>");
            System.exit(1);
        } else {
            String comPortName = args[0];
            System.out.println("Start monitoring serial port " + args[0] + " at 9600 boud rate");
            SwingUtilities.invokeAndWait(()->{
                view = WasteContainerGUI();
            });
            WasteContainerGUI monitor = new WasteContainerGUI();
            CommChannel monitor = new SerialCommChannel(comPortName, 9600);
            new WasteContainerGUI(monitor);
        }
    }
}

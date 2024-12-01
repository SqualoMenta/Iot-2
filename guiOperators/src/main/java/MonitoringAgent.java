public class MonitoringAgent extends Thread {

    CommChannel channel;
    WasteContainerController controller;

    final String ARDUINO_PREFIX = "OUT::";
    final String TEMPERATURE_PREFIX = "T:";
    final String FULLNESS_PREFIX = "W:";
    final String PROBLEM_STR = "P";

    public MonitoringAgent(CommChannel channel, WasteContainerController controller) throws Exception {
        this.controller = controller;
        this.channel = channel;
    }

    public void run() {
        while (true) {
            try {
                String msg = channel.receiveMsg();
                if (msg.startsWith(ARDUINO_PREFIX)) {
                    String cmd = msg.substring(ARDUINO_PREFIX.length());
                    if (cmd.startsWith(TEMPERATURE_PREFIX)) {
                        String arg = cmd.substring(TEMPERATURE_PREFIX.length());
                        controller.setUpTemp(arg);
                    } else if (cmd.startsWith(FULLNESS_PREFIX)) {
                        String arg = cmd.substring(FULLNESS_PREFIX.length());
                        controller.setUpFullness(arg);
                    } else if (cmd.startsWith(PROBLEM_STR)) {
                        controller.problemTemp();
                    }
                }
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }
}

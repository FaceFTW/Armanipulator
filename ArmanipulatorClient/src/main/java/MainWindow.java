import javax.swing.*;
import com.fazecast.jSerialComm.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainWindow {
    private JLabel comPortLabel;
    private JComboBox comPortList;
    private JButton refreshCOMPortButton;

    //Utility Vars
    SerialPort[] comPorts;
    SerialPort currentPort;


    public MainWindow() {
        refreshCOMPortButton.addActionListener(new ActionListener() {           //Implementing refresh
            public void actionPerformed(ActionEvent e) {
                comPorts = SerialPort.getCommPorts();                           //Do the Refresh
                //Update the combobox
                comPortList.removeAllItems();
                for(SerialPort port : comPorts){
                    comPortList.addItem(port.getPortDescription());
                }
            }
        });



    }
}

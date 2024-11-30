import javax.swing.*;

public class LabelObserver implements Observer {
    private JLabel label;

    public void setLabel(JLabel label){
        this.label = label;
    }

    @Override
    public void update(Subject theChangedSubject) {
        if(theChangedSubject instanceof KeyPressSubject){
            label.setText(((KeyPressSubject) theChangedSubject).getKeyName());
        }
    }
}

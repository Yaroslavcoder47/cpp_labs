import javax.swing.*;

public class ListObserver implements Observer{
    private DefaultListModel<String> list;

    public void setList(DefaultListModel<String> list){
        this.list = list;
    }

    @Override
    public void update(Subject theChangedSubject) {
        if(theChangedSubject instanceof KeyPressSubject){
            list.addElement(((KeyPressSubject) theChangedSubject).getKeyName());
        }
    }
}

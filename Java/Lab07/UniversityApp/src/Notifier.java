import java.util.Iterator;
import java.util.Set;

public class Notifier implements Iterable<Student> {
    private final Set<Student> notifiables;

    public Notifier(Set<Student> notifiables){
        this.notifiables = notifiables;
    }

    public void doNotifyAll(String message){
        for(Notifiable object : notifiables){
            object.notify(message);
        }
    }

    @Override
    public Iterator<Student> iterator() {
        return notifiables.iterator();
    }
}
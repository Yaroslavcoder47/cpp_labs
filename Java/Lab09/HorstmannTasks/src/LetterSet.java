import java.util.Set;
import java.util.TreeSet;

/*Letter set*/

public class LetterSet
{
    public Set<String> makeLetterSet(String str)
    {
        Set<String> set = new TreeSet<>();
        for(int i = 0; i < str.length(); ++i){
            set.add(str.substring(i, i + 1));
        }
        return set;
    }
}
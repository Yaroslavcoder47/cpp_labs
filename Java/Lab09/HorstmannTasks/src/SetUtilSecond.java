import java.util.Set;
import java.util.TreeSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

/*Unique words in two string sets*/

public class SetUtilSecond
{

    public static List<Set<String>> uniqueInEach(String[] words1, String[] words2)
    {
        Set<String> set1 = new TreeSet<String>();
        Set<String> set2 = new TreeSet<String>();

        for(String word : words1){
            if(!Arrays.asList(words2).contains(word)){
                set1.add(word);
            }
        }

        for(String word : words2){
            if(!Arrays.asList(words1).contains(word)){
                set2.add(word);
            }
        }
        List<Set<String>> result = new ArrayList<Set<String>>();
        result.add(set1);
        result.add(set2);
        return result;
    }
}
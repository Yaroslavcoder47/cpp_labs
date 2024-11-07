import java.util.Map;
import java.util.TreeMap;


/*Map words to their lengths*/

public class MapUtil
{
    /**
     Make a sorted map whose keys are the given words and whose values are their lengths.
     @param words an array of strings
     @return a map mapping strings to their lengths
     */
    public Map<String, Integer> makeMap(String[] words)
    {
        Map<String, Integer> map = new TreeMap<>();
        for(String word : words){
            map.put(word, word.length());
        }
        return map;
    }
}
import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;

public class MapUtilSecond
{
    /**
     Make a sorted map whose keys are the word lengths words and whose values are
     the sets of the words with the given lengths. The map and sets should be sorted.
     @param words an array of strings
     @return a map mapping strings to their lengths
     */
    public Map<Integer, TreeSet<String>> makeMap(String[] words)
    {
        Map<Integer, TreeSet<String>> map = new TreeMap<>();
        for(String word : words){
            int length = word.length();
            if(!map.containsKey(length)){
                map.put(length, new TreeSet<String>());
            }
            map.get(length).add(word);
        }
        return map;
    }
}

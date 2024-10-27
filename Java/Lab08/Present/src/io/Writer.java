package io;

import present.Candy;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class Writer {

    public static void writeToFile(String fileName, List<Candy> candies){
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))){
            for(Candy item : candies){
                writer.write(item.toString());
            }
        }
        catch(IOException exc){
            System.out.println(exc.getMessage());
        }
    }

    public static StringBuffer writeToString(List<Candy> candies){
        StringBuffer result = new StringBuffer();
        for(Candy item : candies){
            result.append(item.toString());
        }
        return result;
    }
}

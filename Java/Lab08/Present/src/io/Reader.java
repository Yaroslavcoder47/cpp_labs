package io;

import present.*;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Reader {
    public static List<Candy> readFromFile(String fileName){
        List<Candy> result = new ArrayList<>();
        try(BufferedReader reader = new BufferedReader(new FileReader(fileName))){
            String line;
            while((line = reader.readLine()) != null){
                String[] parts = line.split(" ");
                String candy = parts[0];
                int sugar = Integer.parseInt(parts[1]);
                int weight = Integer.parseInt(parts[2]);
                String typeOfCandy = parts[3];
                if(candy.equals("Chocolate")){
                    result.add(new Chocolate(sugar, weight, ChocolateType.valueOf(typeOfCandy)));
                }
                else if(candy.equals("Lollipop")){
                    result.add(new Lollipop(sugar, weight, LollipopColor.valueOf(typeOfCandy)));
                }
            }
        }
        catch (IOException exc) {
            System.out.println(exc.getMessage());
        }
        return result;
    }

    public static void checkFile(String fileName) throws FileNotFoundException {
        File file = new File(fileName);

        if(!file.exists() || !file.isFile()){
            throw new FileNotFoundException("File does not exist!");
        }
    }
}

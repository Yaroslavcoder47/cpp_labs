package io;

import present.Candy;
import present.Chocolate;
import present.Lollipop;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.Map;

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

    public static void WriteToFileSum(List<Candy> candies){
        String fileName = "./data/summaryOfCandies";
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))){
            int sumWeightOfChocolate = 0;
            int sumWeightOfLollipop = 0;
            int countChocolate = 0;
            int countLollipop = 0;
            for(Candy item : candies){
                if(item instanceof Chocolate){
                    sumWeightOfChocolate += item.getWeight();
                    countChocolate++;
                }
                else if(item instanceof Lollipop){
                    sumWeightOfLollipop += item.getWeight();
                    countLollipop++;
                }
            }
            writer.write(String.format("Chocolate weights %d, they occupy %d%%\n", sumWeightOfChocolate,
                    Math.round((double) countChocolate / candies.size() * 100.)));
            writer.write(String.format("Lollipop weights %d, they occupy %d%%", sumWeightOfLollipop,
                    Math.round((double) countLollipop / candies.size() * 100.)));
        }
        catch(IOException exc){
            System.out.println(exc.getMessage());
        }
    }

    public static void writeMapToFile(Map<Integer, List<Candy>> data){
        String fileName = "./data/mapOfCandies";
        StringBuilder builder = new StringBuilder("Map of candies grouped by weight:\n");

        for (Map.Entry<Integer, List<Candy>> entry : data.entrySet()) {
            int weight = entry.getKey();
            List<Candy> candies = entry.getValue();

            builder.append("Weight: ").append(weight).append(" grams\n");
            builder.append("Candies:\n");

            for (Candy candy : candies) {
                builder.append("  - ").append(candy.toString()).append("\n");
            }

            builder.append("\n");
        }

        try(BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))){
            writer.write(builder.toString());
        }
        catch(IOException exc){
            System.out.println(exc.getMessage());
        }

    }
}

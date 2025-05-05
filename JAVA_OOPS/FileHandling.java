import java.io.*;
import java.util.*;

public class FileHandling {
    public static void main(String[] args) throws IOException {
        // Create File
        File f = new File("abc.txt");
        f.createNewFile();

        // Write File
        FileWriter fwr = new FileWriter("abc.txt");
        fwr.write("fscoiety");
        fwr.close();

        // Read File
        Scanner sc = new Scanner(f);
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            System.out.println(line);
        }
        System.out.println("End of file");
        sc.close();

        
        // Word and Sentence cnt
        Scanner scrn = new Scanner(f);

        int wordCount = 0;
        int sentenceCount = 0;

        while (scrn.hasNextLine()) {
            String line = scrn.nextLine();
            String[] words = line.split("\\s+");
            wordCount += words.length;
            sentenceCount += line.split("[.!?]").length;
        }

        scrn.close();

        System.out.println("Number of words: " + wordCount);
        System.out.println("Number of sentences: " + sentenceCount);
    }
}

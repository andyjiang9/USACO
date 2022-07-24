import java.util.*;
import java.io.*;

public class UdderedButNotHerd {

    public static void main(String[] args) throws IOException {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));

        String alph = sc.readLine();
        String word = sc.readLine();
        int times = 0;

        int counter = 0;
        while(counter < word.length()) {
            char letter = word.charAt(counter);

            for(int i =0 ; i < alph.length(); i++) {
                if(counter >= word.length()) break;

                if(alph.charAt(i) == letter) {
                    counter++;
                    if(counter >= word.length()) break;
                    letter = word.charAt(counter);
                }
            }

            times++;
    
        }

        System.out.println(times);
    }
}
    


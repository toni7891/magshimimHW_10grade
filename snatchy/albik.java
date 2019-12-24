import java.util.Random;
import java.util.Scanner;

/**
 * (-)Game of Bulls and cows with [player] and [pc] mode
 * (-)could have done easily using ArrayLists, but was
 *    written using only regular arrays
 * (-) on win prints ascii art (^_^)
 *
 * @author Daniel Deychev
 * @version 1.7.2
 */
public class albik {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int mode;

        do {
            //offer option and ask for value to store in mode
            System.out.println("input:\n(1): for pc mode\n(2): for player mode\n(-1):exit");
            mode = input.nextInt();
            if (mode == 1) {
                System.out.println("Initializing pc mode...");
                startGame(mode);
            } else if (mode == 2) {
                System.out.println("Initializing player mode...");
                startGame(mode);
            } else if (mode != -1){
                System.out.println("Invalid Input!!!");
            }
        } while (mode != -1);
        System.out.println("Bye!");

    }

    /*
    input: Mode - 1 or 2 (sets gameMode)
    output: None
    func.: start game according to chosen mode
     */
    public static void startGame(int mode){
        boolean success = false; //var to check if player won
        int guess, len, tries, rand;
        Scanner input = new Scanner(System.in);

        //get settings from user
        System.out.println("Please input length of number");
        len = input.nextInt();
        System.out.println("Please input max tries");
        tries = input.nextInt();

        rand = randomDiffNum(len);
        System.out.println(rand);
        // let player guess ["tries"] times

        for (int i = 0; i < tries; i++) {
            if (!success) {
                System.out.println("Guess a number");
                if (mode == 1){
                    guess = randomDiffNum(len);
                    System.out.println("my guess: " + guess);
                } else {
                    guess = input.nextInt();
                }

                if (guess == rand) { //correct guess -> finish game
                    success = true;
                    System.out.println("YOU WON!!!!");
                    printHanukkah();
                } else { //incorrect guess -> print hits
                    int[] hits = checkHits(rand, guess, len);
                    System.out.println("Accurate hits: " + hits[0] + ", Partial hits: " + hits[1]);
                }
            }
        }
    }

    /*
    input: length of number to randomize
    output: randomized num (length: len)
    func.: randomly choose num and make sure all digits are different
     */
    public static int randomDiffNum(int len){
        Random r = new Random();
        int min, max, rand;
        //min limit - 10 ^ (len-1) (for 4 it's 4000 = 4 * 10 ^ 3) (inclusive)
        min = (int) Math.pow(10, len-1);
        //max limit - 10 ^ (len) (for 4 it's 40000 = 4 * 10 ^ 4) (exclusive)
        max = (int) Math.pow(10, len);

        do {
            rand = r.nextInt(max - min) + min;
        } while (!checkDiff(rand, len));

        return rand;
    }

    /* input: num - a randomized number , len - num's length

     */
    public static boolean checkDiff(int num, int len){
        int tempNum, count;

        //iterate over all digits (0-9) and all digits in num
        for (int i = 0; i < 10; i++) {
            count = 0;
            tempNum = num;

            for (int j = 0; j < len; j++) {
                if (tempNum % 10 == i){
                    count++;
                }
                tempNum /= 10;
            }
            if (count > 1){
                return false;
            }
        }
        return true;
    }


    /*
    input: base - base number to check on,
    guess - player's guess, baseLen - length of base num
    output: array with the num of accurate and partial hits
    func.: take number check partial and accurate hits, store in array and return
     */
    public static int[] checkHits(int base, int guess, int baseLen){
        int acc = 0;
        int part = 0;
        int currDigit;
        int[] reversedBaseArr = new int[baseLen]; //int of digits of base num (but reversed!)
        int[] result = new int[2];
        int guesslen = 0;
        int tempBase = base;

        while (tempBase != 0){
            tempBase /= 10;
            guesslen++;
        }

        for (int i = 0; i < baseLen; i++){
            reversedBaseArr[i] = base % 10;
            base /= 10;
        }

        for (int i=0; i < guesslen; i++){
            currDigit = guess % 10;
            if (currDigit == reversedBaseArr[i]){
                acc++;
            } else if (digitIsIn(currDigit, reversedBaseArr)){
                part++;
            }
            guess /= 10;
        }
        result[0] = acc;
        result[1] = part;
        return result;
    }

    /*
    input: num - a digit, arr - array
    output: bool
    func.: check if num is in arr, if so return true
     */
    public static boolean digitIsIn(int num, int[] arr){
        for (int i: arr){
            if (i == num){
                return true;
            }
        }
        return false;
    }

    /*
    input: None
    output: None
    func.: print a nice pic for Hanukkah
     */
    public static void printHanukkah(){
        System.out.println("ooooooooooooooooooooooooo");
        System.out.println("o    Happy Hanukkah     o");
        System.out.println("o          ! !          o");
        System.out.println("o        ! | | !        o");
        System.out.println("o      ! | H H | !      o");
        System.out.println("o    ! | H H!H H | !    o");
        System.out.println("o    | H H H|H H H |    o");
        System.out.println("o    (_H_H_H|H_H_H_)    o");
        System.out.println("o     (___________)     o");
        System.out.println("o           H           o");
        System.out.println("o           H           o");
        System.out.println("o           H           o");
        System.out.println("o        ___H___        o");
        System.out.println("ooooooooooooooooooooooooo");

    }
}


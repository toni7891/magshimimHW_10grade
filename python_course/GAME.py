print("CODE BY:")
print("""
     @@@  @@@@@@@   @@@@@@@ @@@  @@@ @@@@@@  @@@@@@@   
    @@@@  @@@@@@@@ @@@@@@@@ @@@  @@@ @@@@@@@ @@@@@@@@  
   @@!@!  @@!  @@@ !@@      @@!  @@@     @@@ @@!  @@@  
  !@!!@!  !@!  @!@ !@!      !@!  @!@     @!@ !@!  @!@  
 @!! @!!  @!@!!@!  !@!      @!@!@!@! @!@!!@  @!@!!@!   
!!!  !@!  !!@!@!   !!!      !!!@!!!! !!@!@!  !!@!@!    
:!!:!:!!: !!: :!!  :!!      !!:  !!!     !!: !!: :!!   
!:::!!::: :!:  !:! :!:      :!:  !:!     :!: :!:  !:!  
     :::  ::   :::  ::: ::: ::   ::: :: :::: ::   :::  
     :::   :   : :  :: :: :  :   : :  : : :   :   : :
""")
print("--------------------------------------------------------")

global old_letters_guessed
global num_of_tries

def print_hangman():
    print("""
      _    _                                         
     | |  | |                                        
     | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __  
     |  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ 
     | |  | | (_| | | | | (_| | | | | | | (_| | | | |
     |_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|
                          __/ |                      
                         |___/
""")


def print_hangman_figures(num_of_tries):
    HANGMAN_PHOTOS = {
        0: "x-------x\n",
        1: "x-------x\n|\n|\n|\n|\n|\n",
        2: "x-------x\n|       |\n|       0\n|\n|\n|\n",
        3: "x-------x\n|       |\n|       0\n|       |\n|\n|\n",
        4: "x-------x\n|       |\n|       0\n|      /|\\\n|\n|\n",
        5: "x-------x\n|       |\n|       0\n|      /|\\\n|      /\n|\n",
        6: "x-------x\n|       |\n|       0\n|      /|\\\n|      / \\ \n|\n"
    }
    print(HANGMAN_PHOTOS[num_of_tries])

def main():
    MAX_TRIES = 6
    num_of_tries = 0
    arrows = " -> "
    print_hangman()
    print("Max tries - ", MAX_TRIES)
    file_path = input("Enter file path: ")
    word_index = int(input("Enter index: "))
    print("\nLet's start!\n")
    secret_word = choose_word(file_path, word_index)
    old_letters_guessed = []
    flag = False
    print_hangman_figures(num_of_tries)
    while check_win(secret_word, old_letters_guessed) != True or flag != True:
        print(show_hidden_word(secret_word, old_letters_guessed))
        # do-while loop
        now_guess = input("Guess a letter: ")
        while try_update_letter_guessed(now_guess, old_letters_guessed) == False:
            now_guess = input("Guess a letter: ")

        if now_guess not in secret_word:
            print(":(")
            print_hangman_figures(num_of_tries)
            num_of_tries += 1
            new_sorted = sorted(old_letters_guessed)
            arrows_str = arrows.join(new_sorted)
            print(arrows_str)

            if num_of_tries == MAX_TRIES:
                print(show_hidden_word(secret_word, old_letters_guessed))
                print("LOSE")
                flag = True
                break

        if check_win(secret_word, old_letters_guessed) == True:
            print(show_hidden_word(secret_word, old_letters_guessed))
            print("WIN")
            flag = True





def show_hidden_word(secret_word, old_letters_guessed):
    no_hidden = ""
    i = 0
    for item in secret_word:
        i += 1
        if item in old_letters_guessed:
            no_hidden += item
            if i != len(secret_word):
                no_hidden += " "
        else:
            no_hidden += "_"
            if i != len(secret_word):
                no_hidden += " "
    return no_hidden


def check_win(secret_word, old_letters_guessed):
    len_of = len(secret_word)
    count_of = 0
    if len_of == 0:
        return True

    for i in secret_word:
        if i in old_letters_guessed:
            count_of += 1

    if count_of == len_of:
        return True
    else:
        return False


def choose_word(file_path, index):
    index -= 1
    with open(file_path, 'r') as f:
        word_list = f.read().split(' ')
    while index >= len(word_list):
        index -= len(word_list)
    return word_list[index]


def try_update_letter_guessed(letter_guessed, old_letters_guessed):
    flag = 0
    arrows = " -> "
    letter_guessed.lower()
    old_new_letters = old_letters_guessed
    if letter_guessed in old_letters_guessed:
        flag = 2
        is_in = True
        print("X")
        new_sorted = sorted(old_letters_guessed)
        arrows_str = arrows.join(new_sorted)
        print(arrows_str)

    else:
        is_in = False
        if letter_guessed.isalpha() == 1 and len(letter_guessed) == 1:
            flag = 1
            old_new_letters += letter_guessed
            return True

    if flag == 0:
        print("X")
        return False

    if len(letter_guessed) == 1 and letter_guessed.isalpha() == 1 and is_in == False:
        return True

def check_valid_input(letter_guessed, old_letters_guessed):
    letter_guessed = letter_guessed.lower()
    if letter_guessed in old_letters_guessed:
        is_in = True
    else:
        is_in = False
    if len(letter_guessed) > 1 or letter_guessed.isalpha() == 0 or is_in == True:
        print("False")
        return False
    if len(letter_guessed) == 1 and letter_guessed.isalpha() == 1 and is_in == False:
        print("True")
        return True

if __name__ == '__main__':
    main()
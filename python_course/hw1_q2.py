def physic_ok(behavior):
    physic = input("What is the physical equivalent of {}?\n".format(behavior))
    physic_op = input(
        'Do you consider the behavior "{}" ok? please write "yes" or "no"\n'.format(physic))
    return physic_op.lower() == 'yes'


def beneficial(behavior):
    num_harmed = int(input("How many people will be harmed if you do it?\n"))
    harm_level = 0
    if num_harmed < 5:
        for person in range(1, num_harmed + 1):
            level = input(
                "What level of harm will be made to the {}st person? please enter a number from 1 to 10\n".format(person))
            harm_level += int(level)
    else:
        harm_level = int(input(
            "what average level of harm is done to each person? please enter a number from 1 to 10\n")) * num_harmed

    num_benefit = int(input("How many people will benefit if you do it?\n"))
    good_level = 0
    if num_benefit < 5:
        for person in range(1, num_benefit):
            good = input(
                "What level of benefit will be made to the {}st person? please enter a number from 1 to 10\n".format(person))
            good_level += int(good)
    else:
        good_level = int(input(
            "what average level of benefit will be made to each person? please enter a number from 1 to 10\n")) * num_benefit

    return good_level > harm_level


def main():
    behavior = input(
        "Welcome to the moral decision making assistant! What is the behavior in question?\n")
    physic_answer = physic_ok(behavior)
    if not(physic_answer):
        print("According to our analysis, you should not to it. Try to find other ways to solve your problem.")
    else:
        beneficent = beneficial(behavior)
        if beneficent:
            print("According to our analysis, you should do it.\nHave a great day!")
        else:
            print(
                "According to our analysis, you should not to it. Try to find other ways to solve your problem.")


if __name__ == "__main__":
    main()

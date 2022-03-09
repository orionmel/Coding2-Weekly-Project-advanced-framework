
import random
print("______________________________________________________________________")
print("                                  Riddle Game")
print("______________________________________________________________________")
print("                                  INSTRUCTIONS")
print("\n 1.Keep in mind the case sensitivity")
print("2. if you want to stop in middle type [stop] ")
print("")

riddlelist = ["What do you call a deer with no eye?",
              "What did a late tomato say to other tomatoes?",
              "I only know 25 letters of the alphabet......why???",
              "What do you call a bee from America?",
              "How do we count cows?",
              "Which is faster, hot or cold?",
              "Why is “dark” is spelled with a “k” not a “c”?",
              "Who is closer to you, your mom or your dad?",
              "What bird lifts heavy things?",
              "What month do soldiers hate?",
              "What room has no walls, no doors, no windows, and no floors?",
              "What two words have thousands of letters in them?",
              "Where can happiness always be found?"]

count = 0
listitem = 0
while listitem <= 10:
    listitem += 1

    rout = random.choice(riddlelist)
    print(rout)

    if rout == "What do you call a deer with no eye?":
        print("hint: think about [eye] and [deer]")
        ans0 = input("Enter your answer:")
        if ans0 == "no idea":
            count += 1
            print("correct")
            print("because no eye deer :)")
            print("___________________________________________________________")
        elif ans0 == "stop" or ans0 == "Stop" or ans0 == "STOP":
                listitem = 11
        else:
            print("incorrect")
            # print("no idea, because no eye deer :)")
            print("___________________________________________________________")

    if rout == "What did a late tomato say to other tomatoes?":
        print("hint: think about [late]")
        ans1 = input("Enter your answer:")
        if ans1 == "i will catch up" or ans1 == "I Will Catch up":
            count += 1
            print("correct")
            print("catchup = ketchup :)")
            print("___________________________________________________________")
        elif ans1 == "stop" or ans1 == "Stop" or ans1 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            # print("i will catchup , catch up = ketchup :)")
            print("___________________________________________________________")

    if rout == "I only know 25 letters of the alphabet......why???":
        print("hint: no hint : )")
        ans2 = input("Enter your answer:")
        if ans2 == "I don't know Y" or ans2 == "i don't know Y":
            count += 1
            print("correct")
            print("Y = why :)")
            print("___________________________________________________________")
        elif ans2 == "stop" or ans2 == "Stop" or ans2 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            # print("I don't know Y ; Y = why :)")
            print("___________________________________________________________")

    if rout == "What do you call a bee from America?":
        print("hint: think about [bee] and [America]")
        ans3 = input("Enter your answer:")
        if ans3 == "usb" or ans3 == "USB":
            count += 1
            print("correct")
            print("usb = US bee :)")
            print("___________________________________________________________")
        elif ans3 == "stop" or ans3 == "Stop" or ans3 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            # print("usb = US bee :)")
            print("___________________________________________________________")

    if rout == "How do we count cows?":
        print("hint: think about [count] and [cows]")
        ans4 = input("Enter your answer:")
        if ans4 == "cowculator" or ans4 == "calculator":
            count += 1
            print("correct")
            print("cowculator = calculator")
            print("___________________________________________________________")
        elif ans4 == "stop" or ans4 == "Stop" or ans4 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            # print("cowculator = calculator")
            print("___________________________________________________________")

    if rout == "Which is faster, hot or cold?":
        print("hint: think about [faster]")
        ans5 = input("Enter your answer:")
        if ans5 == "Hot" or ans5 == "hot":
            count += 1
            print("correct")
            print(" Because you can catch a cold")
            print("___________________________________________________________")
        elif ans5 == "stop" or ans5 == "Stop" or ans5 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            # print("Hot,Because you can catch a cold")
            print("___________________________________________________________")

    if rout == "Why is “dark” is spelled with a “k” not a “c”?":
        print("hint: think about [k] and [c]")
        ans6 = input("Enter your answer:")
        if ans6 == "can't see in the dark":
            count += 1
            print("correct")
            print("you can't c in the dark")
            print("___________________________________________________________")
        elif ans6 == "stop" or ans6 == "Stop" or ans6 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            # print("you can't c(see) in the dark")
            print("___________________________________________________________")

    if rout == "Who is closer to you, your mom or your dad?":
        print("hint: think about [closer]")
        ans7 = input("Enter your answer:")
        if ans7 == "dad"or ans7 == "DAD":
            count += 1
            print("correct")
            print("Mom is close, because dad is farther")
            print("___________________________________________________________")
        elif ans7 == "stop" or ans7 == "Stop" or ans7 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            # print("DAD,Mom is close, because dad is farther")
            print("___________________________________________________________")

    if rout == "What bird lifts heavy things?":
        print("hint: think about [bird]")
        ans8 = input("Enter your answer:")
        if ans8 == "crane" or ans8 == "Crane":
            count += 1
            print("correct")
            print("___________________________________________________________")
        elif ans8 == "stop" or ans8 == "Stop" or ans8 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            print("___________________________________________________________")


    if rout == "What month do soldiers hate?":
        print("hint: think about [hate]")
        ans9 = input("Enter your answer:")
        if ans9 == "march" or ans9 == "March":
            count += 1
            print("correct")
            print("___________________________________________________________")
        elif ans9 == "stop" or ans9 == "Stop" or ans9 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            print("___________________________________________________________")


    if rout == "What room has no walls, no doors, no windows, and no floors?":
        print("hint: something can eat and cook : )")
        ans10 = input("Enter your answer:")
        if ans10 == "mushroom" or ans10 == "Mushroom":
            count += 1
            print("correct")
            print("___________________________________________________________")
        elif ans10 == "stop" or ans10 == "Stop" or ans10 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            print("___________________________________________________________")

    if rout == "What two words have thousands of letters in them?":
        print("hint: a place : )")
        ans11 = input("Enter your answer:")
        if ans11 == "post office" or ans11 == "Post Office":
            count += 1
            print("correct")
            print("because post office has lots of letters")
            print("___________________________________________________________")
        elif ans11 == "stop" or ans11 == "Stop" or ans11 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            # print("post office, because post office has lots of letters")
            print("___________________________________________________________")


    if rout == "Where can happiness always be found?":
        print("hint: think about [found]")
        ans12 = input("Enter your answer:")
        if ans12 == "dictionary" or ans12 == "Dictionary":
            count += 1
            print("correct")
            print("___________________________________________________________")
        elif ans12 == "stop" or ans12 == "Stop" or ans12 == "STOP":
            listitem = 11
        else:
            print("incorrect")
            print("___________________________________________________________")

    print(f"{(count/100)*100}% of your answer were correct")

# import random
# import os
#
# x = 0
# while x == 0:
#     rang1 = int(input("请设置本局游戏的最小值:"))
#     rang2 = int(input("请设置本局游戏的最大值:"))
#     num = random.randint(rang1, rang2)
#     guess = "guess"
#     print("数字猜谜游戏!")
#     i = 0
#     while guess != num:
#         i += 1
#         guess = int(input("请输入你猜的数字:"))
#
#         if guess == num:
#             print("恭喜,你猜对了!")
#         elif guess < num:
#             print("你猜的数小了...")
#         else:
#             print("你猜的数大了...")
#
#     print("你总共踩了%d" % i + "次", end='')
#     print(",快和你朋友较量一下")
#     os.system("pause")
#     os.system("cls")
from find_ft_type import all_thing_is_obj

ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello" : "titi!"}

print("List : ", end='')
all_thing_is_obj(ft_list)
print("Turple : ", end='')
all_thing_is_obj(ft_tuple)
print("Set : ", end='')
all_thing_is_obj(ft_set)
print("Dict : ", end='')
all_thing_is_obj(ft_dict)
print("Brian is in the kitchen : ", end='')
all_thing_is_obj("Brian")
print("Toto is in the kitchen  : ", end='')
all_thing_is_obj("Toto")
print(" : ", end='')
print(all_thing_is_obj(10))
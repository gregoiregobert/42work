def all_thing_is_obj(object: any) -> int:

    """Display the type of the provide object, return 42"""
    type_msg = {
        list: "List : ",
        tuple: "Turple : ",
        set: "Set : ",
        dict: "Dict : ",
        str: "is in the kitchen : ",
    }

    if isinstance(object, (int, float)):
        print("Type not found")
    elif isinstance(object, str):
        print(object, type_msg[type(object)], type(object))
    else:
        print(type_msg[type(object)], type(object))
    return 42

def NULL_not_found(object: any) -> int:

	type_msg = {
		type(None): "Nothing: ",
		float: "Cheese: ",
		int: "Zero: ",
		str: "Empty: ",
		bool: "Fake: "
	}

	if (type(object) in [type(None), float, int, bool]):
		print(type_msg[type(object)], object, type(object))
		return 0

	if type(object) is str and len(object) == 0:
		print(type_msg[type(object)], object, type(object))
		return 0

	else:
		print("Type not found")
		return 1

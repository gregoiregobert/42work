from S1E9 import Character


class Baratheon(Character):
    """Representing the Baratheon family."""

    def __init__(self, first_name, is_alive=True):
        """A Baratheon is born"""
        super().__init__(first_name, is_alive)
        self.family_name = 'Baratheon'
        self.eyes = 'brown'
        self.hairs = 'dark'

    def die(self):
        """A Baratheon is dead"""
        self.is_alive = False

    def __str__(self):
        """Description"""
        Vector = (self.family_name, self.eyes, self.hairs)
        return f"<Vector: {Vector}>"

    def __repr__(self):
        """Link to description"""
        return self.__str__()


class Lannister(Character):
    """Representing the Lannister family."""

    def __init__(self, first_name, is_alive=True):
        """A Lannister is born"""
        super().__init__(first_name, is_alive)
        self.family_name = 'Lannister'
        self.eyes = 'blue'
        self.hairs = 'light'

    def create_lannister(first_name, is_alive):
        """A Lannister has a child"""
        return Lannister(first_name, is_alive)

    def die(self):
        """Kill this character"""
        self.is_alive = False

    def __str__(self):
        """Description"""
        Vector = (self.family_name, self.eyes, self.hairs)
        return f"<Vector: {Vector}>"

    def __repr__(self):
        """Link to description"""
        return self.__str__()

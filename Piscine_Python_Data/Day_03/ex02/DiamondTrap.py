from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    """A king is born"""

    def set_hairs(self, value):
        """Define his hair color"""
        self.hairs = value

    def set_eyes(self, value):
        """Define his eyes color"""
        self.eyes = value

    def get_hairs(self):
        """Get his hair color"""
        return self.hairs

    def get_eyes(self):
        """Get his eyes color"""
        return self.eyes

    def die(self):
        """The king is dead, long live the king"""
        self.is_alive = False

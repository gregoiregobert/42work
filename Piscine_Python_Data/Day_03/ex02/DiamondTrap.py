from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):

    def set_hairs(self, value):
        self.hairs = value

    def set_eyes(self, value):
        self.eyes = value

    def get_hairs(self):
        return self.hairs

    def get_eyes(self):
        return self.eyes

    def die(self):
        self.is_alive = False

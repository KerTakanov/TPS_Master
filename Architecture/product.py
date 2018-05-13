class Product:
    """
    cdc:
        { 'cost': 1..inf,
          'requirements': ['metal', 'wood', 'electronics'],
          'delay': 1..inf,
          'quantity': 1..inf }
    """
    def __init__(self, name, client, cdc):
        self.name = name
        self.cdc = cdc
        self.client = client

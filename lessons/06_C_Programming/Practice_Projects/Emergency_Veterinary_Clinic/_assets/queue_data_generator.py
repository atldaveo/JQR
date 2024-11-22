"""Script to generate binary data files of varying sizes to assist in the
development and grading of the Emergency Veterinary Clinic project.

To execute, place the script in the project directory and run
`python3 queue_data_generator.py` in a terminal to create 3 data files labeled
`<small/medium/large>_queue.dat`.
"""
import struct
import random

MAX_NAME = 32
MAX_SPECIES = 32
MAX_INJURY = 256

DOCTORS = [
    "Dr. McCoy",        # From Star Trek: The Original Series
    "Dr. Crusher",      # From Star Trek: The Next Generation
    "Dr. Bashir",       # From Star Trek: Deep Space Nine
    "Dr. Phlox",        # From Star Trek: Enterprise
    "Dr. Pulaski",      # From Star Trek: The Next Generation
    "Dr. The Doctor",   # From Star Trek: Voyager
    "Dr. Zimmerman",    # From Star Trek: Voyager
    "Dr. Culber",       # From Star Trek: Discovery
    "Dr. Boyce",        # From Star Trek: The Original Series (Pilot)
    "Dr. Selar",        # From Star Trek: The Next Generation
    "Dr. T'Ana",        # From Star Trek: Lower Decks
    "Dr. Finn",         # From Star Trek: Prodigy
]


BLUEY = {
    "Bluey": "Blue Heeler",
    "Bingo": "Red Heeler",
    "Bandit": "Blue Heeler",
    "Chilli": "Red Heeler",
    "Muffin": "Blue Heeler",
    "Socks": "Blue Heeler",
    "Stripe": "Blue Heeler",
    "Trixie": "Blue Heeler",
    "Bob": "Blue Heeler",
    "Nana": "Blue Heeler",
    "Coco": "Poodle",
    "Snickers": "Dachshund",
    "Honey": "Beagle",
    "Mackenzie": "Border Collie",
    "Lucky": "Labrador",
    "Judo": "Chow Chow",
    "Rusty": "Red Kelpie",
    "Indy": "Afghan Hound",
    "Chloe": "Dalmation",
    "Missy": "Australian Terrier",
    "Calypso": "Australian Shepherd",
    "Jack": "Jack Russell"
}

DISNEY = {
    "Simba": "Lion",
    "Nala": "Lion",
    "Bambi": "Deer",
    "Balto": "Husky Mix",
    "Jenna": "Husky",
    "Steele": "Alaskan Malamute",
    "Nikki": "Husky Mix",
    "Kaltag": "Husky Mix",
    "Star": "Husky Mix",
    "Thumper": "Rabbit",
    "Dumbo": "Elephant",
    "Timon": "Meerkat",
    "Pumbaa": "Warthog",
    "Lady": "Cocker Spaniel",
    "Tramp": "Mutt",
    "Scuttle": "Seagull",
    "Flounder": "Fish",
    "Sebastian": "Crab",
    "Baloo": "Bear",
    "Shere Khan": "Tiger",
    "Mufasa": "Lion",
    "Rajah": "Tiger",
    "Meeko": "Raccoon",
    "Stitch": "Extraterrestrial",
    "Tod": "Fox",
    "Copper": "Hound Dog",
    "Bagheera": "Black Panther",
    "Kaa": "Snake",
    "King Louie": "Orangutan",
    "O'Malley": "Cat",
    "Duchess": "Cat",
    "Marie": "Cat",
    "Toulouse": "Cat",
    "Berlioz": "Cat",
    "Sven": "Reindeer",
    "Maximus": "Horse",
    "Olaf": "Snowman",
    "Jiminy Cricket": "Cricket",
    "Figaro": "Cat",
    "Cleo": "Goldfish",
    "Pegasus": "Winged Horse",
    "Mushu": "Dragon",
    "Percy": "Pug",
    "Flit": "Hummingbird",
    "Rutt": "Moose",
    "Tuke": "Moose",
    "Philoctetes": "Satyr"
}

DND = {
    "Thorn": "Manticore",
    "Whisper": "Banshee",
    "Blaze": "Phoenix",
    "Glimmer": "Unicorn",
    "Frostfang": "White Dragon",
    "Stoneheart": "Gargoyle",
    "Rumble": "Earth Elemental",
    "Nether": "Shadow Demon",
    "Aurora": "Fairy Dragon",
    "Mariner": "Kraken",
    "Ember": "Fire Elemental",
    "Torrent": "Water Elemental",
    "Zephyr": "Air Elemental",
    "Boulder": "Stone Giant",
    "Shadow": "Wraith",
    "Starlight": "Celestial",
    "Eclipse": "Nightmare",
    "Fable": "Griffin",
    "Myst": "Specter",
    "Vine": "Treant",
    "Fang": "Wyvern",
    "Sting": "Chimera",
    "Sleet": "Ice Giant",
    "Cinder": "Salamander",
    "Glade": "Dryad",
    "Peak": "Roc",
    "Siren": "Harpy",
    "Twilight": "Dark Elf",
    "Gale": "Storm Giant",
    "Forge": "Fire Giant",
    "Abyss": "Balor",
    "Oracle": "Sphinx",
    "Tempest": "Leviathan",
    "Revenant": "Lich",
    "Bane": "Basilisk",
    "Venom": "Medusa",
    "Guardian": "Minotaur",
    "Warden": "Cyclops",
    "Spirit": "Ghost",
    "Hex": "Hag",
    "Ironclad": "Iron Golem",
    "Crest": "Pegasus",
    "Gloom": "Vampire",
    "Solace": "Werewolf",
    "Bramble": "Satyr",
    "Whirl": "Djinn",
    "Flame": "Ifrit",
    "Glint": "Nymph",
    "Veil": "Faerie",
    "Cobalt": "Blue Dragon",
    "Nova": "Solar",
    "Maelstrom": "Sea Serpent",
    "Dusk": "Doppelganger",
    "Pyre": "Hellhound",
    "Tide": "Merfolk",
    "Quake": "Mountain Troll",
    "Lore": "Brownie",
    "Prowl": "Jaguar Warrior",
    "Arcane": "Magic Construct",
    "Spectre": "Spirit Bear",
    "Blight": "Zombie Dragon",
    "Sage": "Ancient Owl",
    "Mirage": "Miraj",
    "Omen": "Prophet",
    "Seraph": "Angel",
    "Drake": "Dragon",
    "Vortex": "Air Spirit",
    "Crestfall": "Griffin",
    "Silence": "Silent Stalker",
    "Echo": "Echo Spirit",
    "Frostbite": "Frost Giant",
    "Inferno": "Fire Sprite",
    "Cascade": "Water Nymph",
    "Talon": "Hawk Spirit",
    "Mirth": "Laughing Imp",
    "Phantom": "Spectral Wolf",
    "Ethereal": "Ether Dragon",
    "Mystic": "Mystic Ape",
    "Grit": "Earth Troll",
    "Glacier": "Ice Elemental",
    "Avalanche": "Snow Beast",
    "Surge": "Storm Sprite",
    "Howl": "Moon Hound",
    "Spark": "Lightning Elemental",
    "Dawn": "Sun Horse",
    "Lila": "Shadow Cat",
    "Avalon": "Water Dragon",
    "Bramblethorn": "Thorn Sprite",
    "Crimson": "Red Dragon",
    "Dewdrop": "Forest Fairy",
    "Eclipsewing": "Night Griffin",
    "Frostclaw": "Ice Phoenix",
    "Glimmerstone": "Crystal Golem",
    "Hollow": "Ghost Wolf",
    "Iridesce": "Shimmering Serpent",
    "Jadeclaw": "Emerald Dragon",
    "Kismet": "Destiny Sphinx",
    "Lunar": "Moon Rabbit",
    "Mystique": "Enchanted Leopard",
    "Nightshade": "Dark Unicorn",
    "Obsidian": "Black Pegasus",
    "Polaris": "Star Bear",
    "Quartz": "Rock Elemental",
    "Ravenwing": "Shadow Eagle",
    "Silverbane": "Silver Werewolf",
    "Tempestfury": "Storm Harpy",
    "Umbra": "Void Entity",
    "Vigil": "Watcher",
    "Whirlwind": "Wind Djinn",
    "Xenon": "Light Elemental",
    "Yew": "Tree Spirit",
    "Zephyrblade": "Wind Warrior",
    "Amberglow": "Fire Elf",
    "Blizzard": "Snow Dragon",
    "Cerulean": "Blue Phoenix",
    "Duskrunner": "Twilight Stag",
    "Emberheart": "Fire Demon",
    "Flare": "Solar Phoenix",
    "Galeforce": "Sky Giant",
    "Hydra": "Multi-headed Serpent",
    "Infernal": "Hell Fiend",
    "Jubilee": "Festival Sprite",
    "Kaleidoscope": "Color-changing Chameleon",
    "Lorekeeper": "Ancient Librarian",
    "Moonbeam": "Lunar Fairy",
    "Nebula": "Cosmic Dragon",
    "Orcus": "Demon Lord",
    "Pandora": "Mystery Box",
    "Quicksilver": "Mercury Monster",
    "Runic": "Magic Stone",
    "Stardust": "Cosmic Deer",
    "Titan": "Giant",
    "Ursa": "Great Bear",
    "Vortexia": "Portal Mistress",
    "Wisp": "Spirit Light",
    "Xylo": "Wood Nymph",
    "Yggdrasil": "World Tree",
    "Zenith": "Sun Spirit",
    "Arcadia": "Mystic Wolf",
    "Blightmare": "Nightmare Horse",
    "Celestia": "Celestial Unicorn",
    "Draconus": "War Dragon",
    "Eldritch": "Ancient Horror",
    "Fae": "Tiny Fairy",
    "Grim": "Reaper",
    "Halo": "Angel",
    "Ivory": "White Minotaur",
    "Jasper": "Stone Dragon",
    "Kraken": "Sea Monster",
    "Lumin": "Light Dragon",
    "Mirthshade": "Shadow Jester",
    "Nimbus": "Cloud Spirit",
    "Oberon": "Fairy King",
    "Flameo": "Fire Spirit",
    "Quasar": "Star Dragon",
    "Riddle": "Sphinx",
    "Sable": "Dark Phoenix",
    "Thornroot": "Ent",
    "Undine": "Water Spirit",
    "Verdant": "Green Dragon",
    "Entemon": "Forest Guardian",
    "Xanthus": "Golden Steed",
    "Yule": "Winter Spirit",
    "Zion": "Heavenly Beast"
}

INJURIES = {
    "Broken leg": 85,
    "Common Cold": 15,
    "Laceration": 55,
    "Ate too much ice cream": 5,
    "Stepped on a Lego": 20,
    "Sprained wing": 40,
    "Burn from fire breath": 70,
    "Sunburn": 10,
    "Frostbite": 60,
    "Pulled muscle": 30,
    "Lost a tooth": 25,
    "Migraine": 35,
    "Stomach upset from too many berries": 10,
    "Splinter": 5,
    "Hiccups": 1,
    "Chipped horn": 15,
    "Mystical flu": 50,
    "Tail cramp": 20,
    "Whisker fatigue": 3,
    "Magic depletion": 45,
    "Dizzy spells": 30,
    "Conjunctivitis": 20,
    "Allergic to pollen": 10,
    "Belly ache from cursed gold": 25,
    "Torn fin": 40,
    "Excessive snoring": 5,
    "Singularity sneeze": 60,
    "Spooked by a shadow": 5,
    "Ghostly possession": 90,
    "Trapped in a fairy ring": 75,
    "Lost in another dimension": 95,
    "Tangled in own tail": 15,
    "Mirror curse": 70,
    "Ego bruise": 2,
    "Cramp from too much swimming": 20,
    "Broke a fang": 25,
    "Memory fog": 50,
    "Nightmares about gnomes": 8,
    "Polka-dot plague": 30,
    "Enchanted sleep": 65,
    "Overgrown claws": 10,
    "Hit by falling star": 80,
    "Glitter in the eye": 10,
    "Laughing fit": 3,
    "Cursed by a wizard": 85,
    "Molting stress": 20,
    "Sneeze causing a thunderstorm": 45,
    "Hypnotized by a rival": 70,
    "Stuck in a human form": 40,
    "Teleported unexpectedly": 30,
    "unknown":50
}

class Patient:
    """
    A class to represent a patient, typically for a veterinary or fantasy creature care setting.

    Attributes:
        name (str): The name of the patient.
        injury (str): A description of the patient's injury. Defaults to 'unknown'.
        severity (int): The severity of the injury, scaled from 1 (minor) to 99 (life-threatening).
                        Defaults to 50, but is adjusted based on the injury type if known.
        species (str): The species of the patient. Defaults to 'unknown'.

    Methods:
        __init__(self, name, injury="unknown", species="unknown"): Constructs 
        all the necessary attributes for the patient object.
    """

    def __init__(self, name, injury="unknown", species="unknown"):
        self.injury = injury
        self.name = name
        self.severity = 50
        self.species = species
        try:
            self.severity = INJURIES[injury]
        except KeyError:
            self.severity = 50

        if (len(self.name) >= MAX_NAME) or \
           (len(self.injury) >= MAX_INJURY) or \
           (len(species) >= MAX_SPECIES):
            raise ValueError



def write_animal(
        file,
        animal: Patient
    ) -> None:
    """Write an animal's information to the open file object.

    Parameters
    ----------
    file : BufferedWriter
        The opened file object.
    animal : Patient Class
    """
    # Get protocol-specific data fields
    name_len = len(animal.name)
    species_len = len(animal.species)
    desc_len = len(animal.injury)

    # Create bytes object for animal information and write to file
    # If you specify a larger number before the `s` in struct.pack() it will
    # automatically pad it with null bytes up to the desired length.
    animal_format = f"BBBxxxH{MAX_NAME}s{MAX_SPECIES}s{MAX_INJURY}s"
    animal_bytes = struct.pack(
        animal_format,
        animal.severity,
        name_len,
        species_len,
        desc_len,
        animal.name.encode(),
        animal.species.encode(),
        animal.injury.encode()
    )
    file.write(animal_bytes)


def write_queue_data(filename: str, queue_list: list) -> None:
    """Write a queue of animal's to a data file.

    Parameters
    ----------
    filename : str
        The filename to write the animal info to.
    queue_list : list[tuple]
        The queue of animals to write to the data file.
    """
    with open(filename, "wb") as file:
        for animal in queue_list:
            write_animal(file, animal)

def write_doctors(filename:str, doctor_list) -> None:
    """ Write newline seperated doctors for the extra credit"""
    with open(filename, "w", encoding="utf-8") as file:
        for doctor in doctor_list:
            file.write(f"{doctor}\n")

def generate_patients(patient_dict: dict):
    """Generates a list of Patients"""
    patient_list = []

    for key, val in patient_dict.items():
        injury = random.choice(list(INJURIES.keys()))
        patient_list.append(Patient(key, injury, val))

    return patient_list


def main() -> None:
    """The main function for generating all three queue data files."""
    bluey_patients = generate_patients(BLUEY)
    disney_patients = generate_patients(DISNEY)
    fantasy_patients = generate_patients(DND)
    write_queue_data("small_queue.dat", bluey_patients)
    write_queue_data("medium_queue.dat", disney_patients + bluey_patients)
    write_queue_data("large_queue.dat", fantasy_patients + disney_patients + bluey_patients)
    write_doctors("doctors.dat", DOCTORS)

if __name__ == "__main__":
    main()

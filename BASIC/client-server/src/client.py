"""
Author: David Chung
Version: 3 (16JAN25)
Date: 11JAN25
Overview: Python client. Subscribes to port 8080

"""

import socket
import logging
import os

# Configure logging
logging.basicConfig(
    filename = "../client_log.txt",                         # Log file name
    level = logging.INFO,                                   # Log level (INFO logs general operations)
    format = "%(asctime)s - %(levelname)s - %(message)s",   # Log format
    datefmt = "%Y-%m-%d %H:%M:%S"                           # Timestamp format
)

SERVER_HOST = '127.0.0.1'
SERVER_PORT = 8080
BUFFER_SIZE = 1024
CLIENT_DIR = "client-repo/" 
"""Define server address, port, buffer size, and client directory."""

def receive_file(client_socket, filename):
    """Receives a file from the server and saves it in 'client-repo' directory."""
    
    os.makedirs(CLIENT_DIR, exist_ok=True)  # Checks if client repo exists. Make it if not
    file_path = os.path.join(CLIENT_DIR, filename) # Build path {CLIENT_DIR}/{filename}

    # Wait for server confirmation
    start_message = client_socket.recv(BUFFER_SIZE).decode().strip()
    if start_message != "START":
        print(f"Error: File transfer failed or file not found on server.\n")
        return

    with open(file_path, "wb") as file:
        print(f"Receiving file: {filename}...\n")

        while True:
            data = client_socket.recv(BUFFER_SIZE)
            if not data:
                break   # case: connection closed
            if data.decode().strip() == "END":  
                break  # Stop receiving if "END" is received
            
            file.write(data)

    print(f"\nFile saved to {file_path}\n")


def main():
    """main
    Initialize a client socket, connects to the server using the configuration 
    outside of main, send / receive messages, and disconnect.
    """
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        # Connect to the server
        client_socket.connect((SERVER_HOST, SERVER_PORT))
        print(f"\nConnected to server at {SERVER_HOST}:{SERVER_PORT}\n")
        logging.info(f"<Start of communication>")     # Start the client-side log

        while True:
            # Get user input
            message = input("Enter message to send (or type 'exit' to quit): ")

            if message.lower() == 'exit':
                print("\nClosing connection...\n")
                break
            elif not message:
                print("Empty message. Try again.")
                continue
            
            # Send the message to the server
            client_socket.sendall(message.encode())
            print(f"\nSent to server: {message}")
            logging.info(f"Client: {message}")
            print(f"\nAwaiting response from server...\n")

            # If client message starts with file_get()
            if message.startswith("file_get "):
                filename = message.split(" ", 1)[1]     # Extract filename
                receive_file(client_socket, filename)
                logging.info(f"\nClient retrieved {filename} from server\n")
                continue

            # Receive response from the server
            response = client_socket.recv(BUFFER_SIZE).decode()
            print(f"Server responded: {response}\n")
            logging.info(f"Server: {response}")
            if response.lower() == 'exit':
                print("\nServer disconnected\n")
                break

    except Exception as e:
        """Handles runtime error (eg. server disconnects)."""
        print(f"An error occurred: {e}")
        logging.error(f"An error occurred: {e}")

    finally:
        """Close the connection."""
        client_socket.close()
        print("Connection closed\n")
        logging.info(f"<End of communication>")

if __name__ == "__main__":
    main()

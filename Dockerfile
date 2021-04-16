FROM debian:buster

RUN apt-get update && apt-get install cmake gcc g++ libsdl2-dev -y


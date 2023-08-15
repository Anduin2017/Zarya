FROM ubuntu:latest

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y g++
RUN mkdir Bin && g++ ./Program.cpp -o Bin/Program.out

EXPOSE 8080

CMD ["./Bin/Program.out"]

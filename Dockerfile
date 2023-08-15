FROM gcc:latest
WORKDIR /app
COPY . .
RUN g++ ./Program.cpp -o Program.out
EXPOSE 8080
CMD ["./Program.out"]

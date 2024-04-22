# syntax=docker/dockerfile:1
FROM python:3.7-alpine
WORKDIR /app
COPY . .
RUN pip3 install -r requirements.txt
EXPOSE 80
CMD ["flask", "run", "--host=0.0.0.0", "--port=80"]
from django.http import HttpResponse, response
from django.shortcuts import render, get_object_or_404
from .models import Question

# Create your views here.

def index(request):
    latest_question_list = Question.objects.order_by("-pub-date")[:5]
    # template = loader.get_template("polls/index.html")
    # context = {"latest_question_list" : latest_question_list}
    # output = ", ".join([q.question_text for q in latest_question_list])
    context = {"latest_question_list" : latest_question_list}
    return render(request, "pols/index.html", context)

def detail(request, question_id):
    question = get_object_or_404(Question, pk=question_id)
    return render(request, "polls/detail.html", {"question": question})

def results(request, question_id):
    response = "Você está vendo os resultados da pergunta %s"
    return HttpResponse(response % question_id)

def vote(request, question_id):
    return HttpResponse("Você está vontando na pergunta %s." % question_id)

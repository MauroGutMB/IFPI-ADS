package br.edu.ifpi.api_alunos.controller;

import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import br.edu.ifpi.api_alunos.model.Aluno;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/alunos")
public class AlunoController {

  List<Aluno> alunos = new ArrayList<Aluno>(
      List.of(
          new Aluno(1L, "Ana", "ADS"),
          new Aluno(2L, "Carlos", "ADS")));

  @GetMapping("/ola")
  public String ola() {
    return "Olá, turma!";
  }

  @GetMapping("/alunos")
  public List<Aluno> listar() {
    return alunos;
  }

  @GetMapping("/alunos/{id}")
  public String alunos(@PathVariable("id") Long id) {
    String nome = "";
    for (Aluno al : alunos) {
      if (al.id() == id)
        nome = al.nome();
    }
    return "Aluno: " + nome + ", ID: " + id;
  }

  @PostMapping("/aluno")
  public String addAluno(@RequestBody Aluno aluno) {
    if (aluno.id() != null &&
        aluno.nome() != null &&
        aluno.curso() != null) {
      Aluno nAluno = new Aluno(aluno.id(), aluno.nome(), aluno.curso());
      alunos.add(nAluno);
      return "Sucesso ao criar aluno";
    }
    return "Falha ao criar aluno";
  }

  @DeleteMapping("/aluno/{id}")
  public String deleteAluno(@PathVariable("id") Long id){


    for (Aluno al : alunos) {
      if (al.id() == id){
        alunos.remove(al);
        return "Aluno deletado com sucesso!";
      }
    }


    return "Falha ao deletar aluno.";
  }

}

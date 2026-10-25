package ifpi.api;

import java.awt.List;
import java.util.ArrayList;

import ifpi.api.Produto;

import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * ProdutoController
 */

@RestController
@RequestMapping("/v1")
public class ProdutoController {

  ArrayList<Produto> produtos = new ArrayList<>();

  @GetMapping
  public String checkhealth(){
    return "este endpoint está saudável";
  }

  @PostMapping("/produto")
  public String produtoInsere(@RequestBody Produto produto){
    produtos.add(produto);

    return "Produto cadastrado com sucesso!";
  }

  @GetMapping("/produtos")
  public ArrayList<Produto> getProdutos(){
    return produtos;
  }

  @DeleteMapping("/produtos")
  public String deleteById(@RequestBody Produto prod){
    for(Produto p : produtos){
      if(prod.getId() == p.getId()){
        produtos.remove(p);
        return "Produto deletado com sucesso!";
      }
    }

    return "Produto não encontrado!";
  }
  
}

package ifpi.api;

/**
 * Produto
 */
public class Produto {

  private Long id;
  private String nome;
  private double preco;
  private boolean destaque;

  Produto(){}

  Produto(Long id, String nome, double preco, boolean destaque){
    this.id = id;
    this.nome = nome;
    this.preco = preco;
    this.destaque = destaque;
  }

  public Long getId() {
    return id;
  }
  public void setId(Long id) {
    this.id = id;
  }

  public String getNome() {
    return nome;
  }
  public void setNome(String nome) {
    this.nome = nome;
  }

  public double getPreco() {
    return preco;
  }
  public void setPreco(double preco) {
    this.preco = preco;
  }

  public boolean getDestaque(){
    return destaque;
  }
  public void setDestaque(boolean destaque) {
    this.destaque = destaque;
  }
  
}

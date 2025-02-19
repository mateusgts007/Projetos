import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/*
converte os valores string da senha para hexadecimal
 */
public class HashUtil {

    public static String hashSenha(String senha) {

        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hash = digest.digest(senha.getBytes());

            /// Converter os bytes para uma representação em hexadecimal
            StringBuilder hexString = new StringBuilder();
            for (byte b : hash) {
                hexString.append(String.format("%02x", b));
            }

            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException("Erro ao calcular hash da senha", e);
        }
    }
}
